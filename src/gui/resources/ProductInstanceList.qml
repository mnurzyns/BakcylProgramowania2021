import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import ProductInstance 1.0

Frame {
    width: parent.width

    ListView {
        implicitHeight: 180
        implicitWidth: parent.width
        clip: true
        spacing: 1

        model: ProductInstanceModel { }

        delegate: RowLayout {
            width: parent.width

            Text {
                Layout.alignment: Qt.AlignLeft
                Layout.minimumWidth: parent.width * 0.07

                text: "ID: " + model.ID
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                font.pointSize: 11
            }

            Text {
                Layout.alignment: Qt.AlignRight

                text: model.Location
                horizontalAlignment: Text.AlignHCenter
                color: "#383737"
                font.pointSize: 9
            }
        }
    }
}
