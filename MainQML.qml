import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Rectangle
{
    id: main
    color: "lightgray"
    visible: true

    Rectangle
    {
        id: rightBlock
        width: parent.width * 0.7
        height: parent.height

        TextEdit
        {
            id: inputText
            width: parent.width
            height: parent.height
            focus: true
            x: 5
            font.pixelSize: 14
            selectByMouse: true
            wrapMode: TextEdit.WordWrap
            font.family: "Helvetica"
            text: "Новая задача"
        }
    }

    Rectangle
    {
        id: leftBlock
        color: "gray"
        width: parent.width * 0.3
        height: parent.height
        x: parent.width * 0.7


        Rectangle
        {
            id: rectDeadline
            color: "#e0e0e0"
            width: parent.width
            height: 28
            Label
            {
                text: "Дедлайн"
                font.pixelSize: 14
                font.bold: true
                width: parent.width
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle
        {
            id: line1
            color: "black"
            width: parent.width
            height: 1
            anchors.top: rectDeadline.bottom;
        }

        Rectangle
        {
            id: rectDeadlineInput
            color: "white"
            width: parent.width
            height: 28
            anchors.top: line1.bottom

            TextInput
            {
                id: inputDeadLine
                width: parent.width
                height: parent.height
                font.bold: true
                font.pixelSize: 14
                verticalAlignment: TextInput.AlignVCenter
                horizontalAlignment: TextInput.AlignHCenter
                inputMethodHints: Qt.ImhDate
                inputMask: "99.99.9999"
                text: new Date().toLocaleDateString("dd.MM.yyyy")
            }
        }

        Rectangle
        {
            id: line2
            color: "black"
            width: parent.width
            height: 1
            anchors.top: rectDeadlineInput.bottom;
        }

        Rectangle
        {
            id: rectProgress
            color: "#e0e0e0"
            width: parent.width
            height: 28
            anchors.top: line2.bottom;
            Label
            {
                text: "Прогресс"
                font.pixelSize: 14
                font.bold: true
                width: parent.width
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle
        {
            id: line3
            color: "black"
            width: parent.width
            height: 1
            anchors.top: rectProgress.bottom;
        }

        Rectangle
        {
            id: rectProgressBox
            color: "#e0e0e0"
            width: parent.width
            height: 28
            anchors.top: line3.bottom

            ComboBox {
                id: inputComboBox
                width: parent.width
                height: parent.height
                font.bold: true
                font.pixelSize: 14
                editable: true
                model: 11
                validator: IntValidator {bottom: 0; top: 10;}
                focus: true
            }
        }

        Rectangle
        {
            id: line4
            color: "black"
            width: parent.width
            height: 1
            anchors.top: rectProgressBox.bottom;
        }

        Button
        {
            signal sendInfo(string deadlne, string taskText, string progress)

            id: control
            text: "Добавить"
            objectName: "addButton"
            width: parent.width
            height: 29
            anchors.top: line4.bottom
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
    }
}
