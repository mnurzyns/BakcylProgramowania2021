import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import Searchbox 1.0
import Product 1.0

Frame {
    ListView {
        implicitHeight: 250
        implicitWidth: Window.width * 0.95
        clip: true
        spacing: 1

        model: ProductModel { }

        delegate: RowLayout {
            width: parent.width

            Text {
                Layout.alignment: Qt.AlignLeft
                Layout.minimumWidth: parent.width * 0.07

                text: "ID: " + model.ID
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                font.pointSize: 12
            }

            Text {
                text: model.Name
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 11
            }

            Text {
                Layout.alignment: Qt.AlignRight

                text: model.Description
                horizontalAlignment: Text.AlignHCenter
                color: "#383737"
                font.pointSize: 9
            }
        }
    }
}
