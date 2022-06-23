import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import Searchbox 1.0
import Product 1.0

Frame {
    property var productModel: productModel
    GridLayout {
        id: productListBaseGrid
        anchors.fill: parent
        flow: GridLayout.TopToBottom

        RowLayout {
            id: headerRow
            spacing: 5

            GroupBox {
                Layout.preferredWidth: parent.width / 10

                Text {
                    text: "ID"
                    font.bold: true
                    font.pointSize: 12
                }

                background: Rectangle {
                    color: "#dddddd"
                }
            }

            GroupBox {
                Layout.preferredWidth: parent.width / 5

                Text {
                    text: "Name"
                    font.bold: true
                    font.pointSize: 12
                }

                background: Rectangle {
                    color: "#dddddd"
                }
            }

            GroupBox {
                Layout.fillWidth: true

                Text {
                    text: "Description"
                    font.bold: true
                    font.pointSize: 12
                }

                background: Rectangle {
                    color: "#dddddd"
                }
            }
        }

        ListView {
            id: listOfProducts
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            spacing: 3

            model: ProductModel { 
                id: productModel 
            }
            
            Loader {
                id: productPageLoader
                property int productId : 0
            }

            delegate: RowLayout {
                width: parent.width
                spacing: 5

                GroupBox {
                    id: idGroupBox
                    Layout.preferredWidth: parent.width / 10
                    clip: true

                    Text {
                        id: idField
                        width: parent.width

                        text: "ID: " + model.ID
                        font.bold: true
                        font.pointSize: 12

                        color: inspectProductlink.containsMouse ? "blue" : "black"
                        font.underline: inspectProductlink.containsMouse
                    }

                    background: Rectangle {
                        color: "#efefef"

                        MouseArea {
                            id: inspectProductlink
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            hoverEnabled: true

                            onClicked: {
                                productPageLoader.source = ""

                                productPageLoader.productId = model.ID
                                productPageLoader.source = "ProductWindow.qml"
                            }
                        }
                    }
                }

                GroupBox {
                    id: nameGroupBox
                    Layout.preferredWidth: parent.width / 5
                    clip: true

                    Text {
                        width: parent.width
                        text: model.Name
                        font.pointSize: 11
                    }

                    background: Rectangle { }
                }

                GroupBox {
                    id: descriptionGroupBox
                    Layout.fillWidth: true
                    clip: true

                    Text {
                        width: parent.width
                        text: model.Description
                        horizontalAlignment: Text.AlignRight
                        color: "#383737"
                        font.pointSize: 9
                    }

                    background: Rectangle { }
                }
            }
        }
    }
}
