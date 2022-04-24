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

    Loader {
        id: addProductPageLoader
    }

    GridLayout {
        id: baseGrid
        anchors.fill: parent
        anchors.margins: 10
        rowSpacing: 5
        flow: GridLayout.TopToBottom

        GridLayout {
            id: searchboxGrid
            Layout.fillWidth: true
            flow: GridLayout.LeftToRight
            columnSpacing: 5

            TextField {
                id: productNamefield
                Layout.fillWidth: true

                onAccepted: searchController.setSearchboxText(
                                productNamefield.text
                            )

                Text {
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    anchors.leftMargin: 8

                    text: "Enter product ID or name"
                    color: "#aaaaaa"
                    font.pixelSize: 25
                    visible: !productNamefield.text && !productNamefield.activeFocus
                }
            }

            Button {
                id: searchButton
                text: "search"

                onClicked: searchController.setSearchboxText(
                               productNamefield.text
                            )
            }

            Button {
                id: addProductButton
                text: "add Product"

                onClicked: {
                    addProductPageLoader.source = ""
                    addProductPageLoader.source = "AddProductWindow.qml"
                }
            }
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

