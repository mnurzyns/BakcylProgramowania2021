import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import ProductDataHandler 1.0

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Product view")

    ProductDataHandler {
        id: productData
    }

    Connections {
        target: productData

        function onProductDataChanged() {
            productIdField.text = "ID: " + productData.productId
            productNameField.text = productData.productName
            productCategoryField.text = productData.productCategory
            productQuantityField.text = productData.productQuantity
            productDescriptionField.text = productData.productDescription
        }
    }

    Component.onCompleted: {
        productData.getProductData(productId)
    }

    GridLayout {
        anchors.fill: parent
        anchors.margins: 10
        rowSpacing: 5
        flow: GridLayout.TopToBottom

        GridLayout {
            Layout.fillWidth: true
            anchors.margins: 5
            rowSpacing: 7
            flow: GridLayout.LeftToRight

            GroupBox {
                implicitWidth: parent.width / 2

                GridLayout {
                    width: parent.width
                    flow: Grid.TopToBottom

                    GroupBox {
                        Layout.fillWidth: true
                        background: Rectangle {
                            Layout.fillWidth: true
                            color: "#dddddd"
                        }

                        Text {
                            id: productIdField
                            text: "Ex ID"
                            font.pointSize: 15
                            font.bold: true
                        }
                    }

                    Text {
                        id: productNameField
                        text: "Ex Name"
                        font.pointSize: 15
                    }

                    Text {
                        id: productCategoryField
                        text: "Ex Category"
                        font.pointSize: 15
                    }

                    Text {
                        id: productQuantityField
                        text: "Quantity: Na"
                        font.pointSize: 15
                    }
                }
            }

            GroupBox {
                implicitHeight: parent.height
                Layout.fillWidth: true

                background: Rectangle {
                    anchors.fill: parent
                    color: "#2f2f2f"
                }

                Text {
                    width: parent.width

                    id: productDescriptionField
                    color: "#ffffff"
                    text: "Ex description"
                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                }
            }
        }

        ProductInstanceList {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
