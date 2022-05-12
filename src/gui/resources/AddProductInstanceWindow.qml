import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import DatabaseManager 1.0

Window {
    id: addProductInstanceWindow
    width: 640
    height: 400
    visible: true
    title: qsTr("Add new Product instance")

    DatabaseManager {
        id: databaseManager
    }

    Popup {
        id: successBox
        width: 400
        height: 150
        modal: true
        focus: true
        anchors.centerIn: Overlay.overlay
        padding: 30

        onClosed: addProductInstanceWindow.close()

        GridLayout {
            anchors.fill: parent
            flow: GridLayout.TopToBottom
            columnSpacing: 20

            Text {
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                text: "Product instance succesfully added"
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

                text: "Enter product instance details below"
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

                    text: productId

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
                    text: "Product instance ID:"
                    font.pointSize: 11
                }
                TextField {
                    implicitWidth: parent.width / 2
                    id: productInstanceIdField

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
                    text: "Product instance Location:"
                    font.pointSize: 11
                }
                TextField {
                    implicitWidth: parent.width / 2
                    id: productInstanceLocationField
                }
            }

            GridLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.leftMargin: 25; Layout.rightMargin: 25
                flow: GridLayout.LeftToRight

                Text {
                    Layout.fillWidth: true
                    text: "Product instance Quantity:"
                    font.pointSize: 11
                }
                TextField {
                    implicitWidth: parent.width / 2
                    id: productInstanceQuantityField

                    validator: IntValidator { }
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
                    databaseManager.createNewProductInstance(
                        parseInt(productIdField.text),
                        parseInt(productInstanceIdField.text),
                        productInstanceLocationField.text,
                        parseInt(productInstanceQuantityField.text)
                    )

                    successBox.open()
                }
            }
        }
    }
}
