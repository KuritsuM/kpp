import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls

import "core"

Window {
    width: 640
    height: 480
    visible: true
    color: "#555753"
    title: qsTr("Hello World")
    
    TextInput {
        id: textInput
        x: 100
        y: 32
        width: 380
        height: 109
        color: "#eeeeec"
        text: qsTr("Text Input")
        font.pixelSize: 12
        selectionColor: "#2c2cad"
    }
    
    TextInput {
        id: textInput1
        x: 100
        y: 169
        width: 380
        height: 129
        text: qsTr("Text Input")
        font.pixelSize: 12
    }

    Text {
        id: cmpResult
        x: 308
        y: 362
        width: 213
        height: 32
        text: qsTr("Результат сравнения")
        font.pixelSize: 12
    }

    Button {
        id: roundButton
        x: 131
        y: 362
        label: "CMP"

        function cmpClicked() {
            if (textInput1.text.localeCompare(textInput.text)) {
                cmpResult.text = "Результат сравнения - не равно";
            }
            else {
                cmpResult.text = "Результат сравнения - равно";
            }

        }

        onButtonClick: {
            cmpClicked();
        }
    }

    Button {
        id: button
        x: 510
        y: 32
        width: 55
        height: 22
        color: "#73d216"
        label: "save"

        onButtonClick: {
            textFieldFileWorker.saveToFile("text_field1_value.txt", textInput.text);
        }
    }

    Button {
        id: button1
        x: 510
        y: 119
        width: 55
        height: 22
        color: "#edd400"
        label: "open"

        onButtonClick: {
            let savedToFile = textFieldFileWorker.openFromFile("text_field1_value.txt");
            textInput.text = savedToFile;
        }
    }

    Button {
        id: button2
        x: 510
        y: 169
        width: 55
        height: 22
        color: "#73d216"
        label: "save"

        onButtonClick: {
            textFieldFileWorker.saveToFile("text_field2_value.txt", textInput1.text);
        }
    }

    Button {
        id: button3
        x: 510
        y: 276
        width: 55
        height: 22
        color: "#edd400"
        label: "open"

        onButtonClick: {
            let savedToFile = textFieldFileWorker.openFromFile("text_field2_value.txt");
            textInput1.text = savedToFile;
        }
    }
}
