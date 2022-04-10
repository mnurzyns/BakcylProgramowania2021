import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import ProductInstance 1.0

Frame {
    ListView {
        anchors.fill: parent
        clip: true
        spacing: 1

        model: ProductInstanceModel { }

        delegate: RowLayout {
            width: parent.width

            Text {
                Layout.alignment: Qt.AlignLeft
                Layout.preferredWidth: 40

                text: "ID: " + model.ID
                horizontalAlignment: Text.AlignLeft
                font.bold: true
                font.pointSize: 11
            }

            Text {
                Layout.alignment: Qt.AlignRight

                text: model.Location
                horizontalAlignment: Text.AlignRight
                color: "#383737"
                font.pointSize: 9
            }
        }
    }
}
