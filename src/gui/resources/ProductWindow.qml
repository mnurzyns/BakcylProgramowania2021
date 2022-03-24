import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import ProductDataHandler 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Product view")

    ProductDataHandler {
        id: productData
    }

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 5

        Rectangle {
            id: productDataSection
            width: parent.width
            height: 250
            color: "#f1f1f1"

            border.color: "#6b6b6b"
            border.width: 2

            Column {
                width: parent.width
                spacing: 7
                leftPadding: 5

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

                Text {
                    id: productDescriptionField
                    color: "#737373"
                    text: "Ex description"
                    font.pointSize: 10
                }
            }
        }
    }
}
