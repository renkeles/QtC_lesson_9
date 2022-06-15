import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Button
{
    signal sendInfo(string deadlne, string taskText, string progress)

    id: control
    text: "Добавить"
    objectName: "addButton"
    width: 640 * 0.3
    height: 29
    //anchors.top: line4.bottom
    font.bold: true
    font.pixelSize: 14

    onClicked:
    {
        if(inputText.text.length)
        {
            sendInfo(inputDeadLine.text.toString(), inputText.text.toString(),  inputComboBox.currentText.toString())
        }
    }

}
