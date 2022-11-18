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
}
