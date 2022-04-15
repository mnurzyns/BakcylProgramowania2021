import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import Searchbox 1.0

Window {
    width: 640
    height: 400
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

            background: Rectangle {
                color: "#dbdbdb"
            }

            Text {
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter

                text: "Enter product details below"
                font.pointSize: 14
            }
        }

        GridLayout {
            Layout.fillWidth: true
            flow: GridLayout.TopToBottom
            rowSpacing: 10

            GridLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.leftMargin: 25; Layout.rightMargin: 25
                flow: GridLayout.LeftToRight

                Text {
                    Layout.fillWidth: true
                    text: "Product ID:"
                    font.pointSize: 11
                }
                TextField {
                    implicitWidth: parent.width / 2
                    id: productIdField
                }
            }

            GridLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.leftMargin: 25; Layout.rightMargin: 25
                flow: GridLayout.LeftToRight

                Text {
                    Layout.fillWidth: true
                    text: "Product Name:"
                    font.pointSize: 11
                }
                TextField {
                    implicitWidth: parent.width / 2
                    id: productNameField
                }
            }

            GridLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.leftMargin: 25; Layout.rightMargin: 25
                flow: GridLayout.LeftToRight

                Text {
                    Layout.fillWidth: true
                    text: "Product Categories:"
                    font.pointSize: 11
                }
                TextField {
                    implicitWidth: parent.width / 2
                    id: productCategoriesField
                }
            }

            GridLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.leftMargin: 25; Layout.rightMargin: 25
                flow: GridLayout.LeftToRight

                Text {
                    Layout.fillWidth: true
                    text: "Product Description:"
                    font.pointSize: 11
                }
                Flickable {
                    implicitWidth: parent.width / 2
                    Layout.fillHeight: true

                    TextArea.flickable: TextArea{
                        id: productDescriptionArea
                        wrapMode: TextArea.Wrap

                        background: Rectangle {
                            border.width: 2
                            border.color: "#aaaaaa"
                        }
                    }
                    ScrollBar.vertical: ScrollBar { }
                }
            }

        }

        GridLayout {
            id: buttonGroup
            flow: GridLayout.LeftToRight
        }
    }
}
