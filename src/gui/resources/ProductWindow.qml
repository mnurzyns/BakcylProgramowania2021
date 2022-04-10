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
            productIdField.text = productData.productId
            productNameField.text = productData.productName
            productCategoryField.text = productData.productCategory
            productQuantityField.text = productData.productQuantity
            productlocationField.text = productData.productLocation
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

        GroupBox {
            id: productDataSection
            Layout.fillWidth: true

            GridLayout {
                Layout.fillWidth: true
                anchors.margins: 5
                rowSpacing: 7
                flow: GridLayout.LeftToRight

                GridLayout {
                    flow: Grid.TopToBottom

                    Text {
                        id: productIdField
                        text: "Ex ID"
                        font.pointSize: 15
                        font.bold: true
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

                    Text {
                        id: productlocationField
                        text: "Ex location"
                        font.pointSize: 12
                    }
                }

                Text {
                    id: productDescriptionField
                    color: "#737373"
                    text: "Ex description"
                    font.pointSize: 10
                }
            }
        }

        ProductInstanceList {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
