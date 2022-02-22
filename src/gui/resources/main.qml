import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: testCol
        anchors.fill: parent
        anchors.margins: 5
        spacing: 3

        Rectangle {
            id: frame
            width: parent.width
            height: 25
            border.color: 'gray'
            border.width: 1

            TextInput {
                id: inputProductName
                anchors.fill: parent
                anchors.margins: 4
            }
        }

        Button {
            id: searchButton
            text: "search"

            onClicked: searchController.SeachButtonPressed()
        }
    }
}

