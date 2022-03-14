import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import Searchbox 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    SearchboxController {
        id: searchController
    }

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

            onClicked: searchController.setSearchboxText(
                           inputProductName.text
                           )
        }

        Text {
            id: testSearchText
            text: searchController.searchboxText
        }
    }

    ProductList {
        anchors.centerIn: parent

    }
}

