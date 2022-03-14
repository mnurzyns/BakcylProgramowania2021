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
                text: "id: NA"
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                font.pointSize: 12
            }

            Text {
                text: "Name of Product"
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 11
            }

            Text {
                text: "The description of the product, (can be longer)"
                horizontalAlignment: Text.AlignHCenter
                color: "#383737"
                font.pointSize: 9
            }
        }
    }
}
