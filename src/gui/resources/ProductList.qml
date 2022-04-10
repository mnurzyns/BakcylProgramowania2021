import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import Searchbox 1.0
import Product 1.0

Frame {
    ListView {
        anchors.fill: parent
        clip: true
        spacing: 1

        model: ProductModel { }

        Loader {
            id: productPageLoader
            property int productId : 0
        }

        delegate: RowLayout {
            width: parent.width

            Text {
                id: idField
                Layout.alignment: Qt.AlignLeft
                Layout.preferredWidth: 40

                text: "ID: " + model.ID
                font.bold: true
                font.pointSize: 12

                color: inspectProductlink.containsMouse ? "blue" : "black"
                font.underline: inspectProductlink.containsMouse

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

            Text {
                text: model.Name
                font.pointSize: 11
            }

            Text {
                Layout.alignment: Qt.AlignRight

                text: model.Description
                color: "#383737"
                font.pointSize: 9
            }
        }
    }
}
