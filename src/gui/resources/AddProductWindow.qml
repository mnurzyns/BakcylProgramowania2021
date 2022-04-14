import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import Searchbox 1.0

Window {
    width: 640
    height: 360
    visible: true
    title: qsTr("Add new Product")

    GridLayout {
        id: baseGrid
        anchors.fill: parent
        anchors.margins: 10
        rowSpacing: 5
        flow: GridLayout.TopToBottom

        GroupBox {
            id: windowTitle
            Layout.fillWidth: true

        }

        GridLayout {
            Layout.fillWidth: true
            flow: GridLayout.LeftToRight
            columnSpacing: 10

            GridLayout {
                id: descriptionGroup
            }

            GridLayout {
                id: textFieldGroup
            }
        }

        GridLayout {
            id: buttonGroup
            flow: GridLayout.LeftToRight

        }
    }
}
