import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import Searchbox 1.0

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Hello World")

    SearchboxController {
        id: searchController
    }

    GridLayout {
        id: baseGrid
        anchors.fill: parent
        anchors.margins: 10
        rowSpacing: 5
        flow: GridLayout.TopToBottom

        TextField {
            id: productNamefield
            Layout.fillWidth: true
        }

        Button {
            id: searchButton
            text: "search"

            onClicked: searchController.setSearchboxText(
                           productNamefield.text
                            )
        }

        Text {
            id: testSearchText
            text: searchController.searchboxText
        }

        ProductList {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}

