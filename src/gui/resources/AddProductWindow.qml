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
                Layout.leftMargin: 25; Layout.rightMargin: 25
                flow: GridLayout.LeftToRight

                Text {
                    Layout.fillWidth: true
                    text: "Product ID:"
                    font.pointSize: 11
                }
                TextField {
                    Layout.fillWidth: true
                    id: productIdField
                }
            }

            GridLayout {
                Layout.fillHeight: true
                Layout.leftMargin: 25; Layout.rightMargin: 25
                flow: GridLayout.LeftToRight

                Text {
                    Layout.fillWidth: true
                    text: "Product ID:"
                    font.pointSize: 11
                }
                TextField {
                    Layout.fillWidth: true
                    id: productNameField
                }
            }

            GridLayout {
                Layout.fillHeight: true
                Layout.leftMargin: 25; Layout.rightMargin: 25
                flow: GridLayout.LeftToRight

                Text {
                    Layout.fillWidth: true
                    text: "Product ID:"
                    font.pointSize: 11
                }
                TextField {
                    Layout.fillWidth: true
                    id: productCategoriesField
                }
            }

            GridLayout {
                Layout.fillHeight: true
                Layout.leftMargin: 25; Layout.rightMargin: 25
                flow: GridLayout.LeftToRight

                Text {
                    Layout.fillWidth: true
                    text: "Product ID:"
                    font.pointSize: 11
                }
                TextArea {
                    Layout.fillWidth: true
                    id: productDescriptionArea
                    placeholderText: qsTr("Enter description")

                    background: Rectangle {
                        border.color: "#6f6f6f"
                        border.width: 2
                    }
                }
            }

        }

        GridLayout {
            id: buttonGroup
            flow: GridLayout.LeftToRight

        }
    }
}
