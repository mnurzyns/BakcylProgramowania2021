import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import Searchbox 1.0

Frame {
    ListView {
        implicitHeight: 250
        implicitWidth: Window.width * 0.95
        clip: true
        spacing: 1

        model: ListModel {
            ListElement {
                ProductId: "1"
                ProductName: "Exmample 1"
                ProductDesc: "The description of the product, (can be longer)"
            }
            ListElement {
                ProductId: "2"
                ProductName: "Exmample 2"
                ProductDesc: "The description of the product, (can be longer)"
            }
            ListElement {
                ProductId: "3"
                ProductName: "Exmample 3"
                ProductDesc: "The description of the product, (can be longer)"
            }
        }

        delegate: RowLayout {
            width: parent.width

            Text {
                Layout.alignment: Qt.AlignLeft
                Layout.minimumWidth: parent.width * 0.07

                text: "ID: " + model.ProductId
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                font.pointSize: 12
            }

            Text {
                text: model.ProductName
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 11
            }

            Text {
                Layout.alignment: Qt.AlignRight

                text: model.ProductDesc
                horizontalAlignment: Text.AlignHCenter
                color: "#383737"
                font.pointSize: 9
            }
        }
    }
}
