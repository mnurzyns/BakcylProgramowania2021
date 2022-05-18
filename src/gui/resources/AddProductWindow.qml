import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import Searchbox 1.0
import DatabaseManager 1.0

Window {
    id: addProductWindow
    width: 640
    height: 400
    visible: true
    title: qsTr("Add new Product")

    DatabaseManager {
        id: databaseManager
    }

    Popup {
        id: successBox
        width: 300
        height: 150
        modal: true
        focus: true
        anchors.centerIn: Overlay.overlay
        padding: 30

        onClosed: addProductWindow.close()

        GridLayout {
            anchors.fill: parent
            flow: GridLayout.TopToBottom
            columnSpacing: 20

            Text {
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                text: "Product succesfully added"
                font.pointSize: 14
            }
            Button {
                id: closeSuccessBoxButton
                Layout.alignment: Qt.AlignCenter
                text: "OK"

                onClicked: close()
            }
        }
    }

    Popup {
        id: failBox
        width: 350
        height: 200
        modal: true
        focus: true
        anchors.centerIn: Overlay.overlay
        padding: 30

        GridLayout {
            anchors.fill: parent
            flow: GridLayout.TopToBottom

            Text {
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                text: "Query failed"
                font.pointSize: 14
            }
            Text {
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                text: databaseManager.failMessageForProduct
                font.pointSize: 11
            }
            Text {
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                text: "Pleas try again"
                font.pointSize: 10
                color: "#333333"
            }
            Button {
                id: closeFailBoxPopup
                Layout.alignment: Qt.AlignCenter
                text: "OK"

                onClicked: close()
            }
        }
    }

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

                    validator: IntValidator { }
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
            Layout.margins: 25
            columnSpacing: 25

            Rectangle {
                id: spacerObject
                Layout.fillWidth: true
            }
            Button {
                id: cancelButton
                text: "Cancel"

                onClicked: close()
            }
            Button {
                id: confirmButton
                text: "Confirm"

                onClicked: {
                    databaseManager.createNewProduct(
                        parseInt(productIdField.text),
                        productNameField.text,
                        productCategoriesField.text,
                        productDescriptionArea.text
                    ) ? successBox.open() : failBox.open()
                }
            }
        }
    }
}
