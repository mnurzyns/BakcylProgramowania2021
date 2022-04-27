import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import ProductInstance 1.0

Frame {
    GridLayout {
        id: productInstanceBaseGrid
        anchors.fill: parent
        flow: GridLayout.TopToBottom

        RowLayout {
            id: headerRow
            spacing: 5

            GroupBox {
                Layout.preferredWidth: parent.width / 10

                Text {
                    text: "ID"
                }
            }

            GroupBox {
                Layout.fillWidth: true

                Text {
                    text: "Location"
                }
            }
        }

        ListView {
            id: listOfProductInstances
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            spacing: 1

            model: ProductInstanceModel { }

            delegate: RowLayout {
                width: parent.width

                Text {
                    Layout.alignment: Qt.AlignLeft
                    Layout.preferredWidth: 40

                    text: "ID: " + model.ID
                    font.bold: true
                    font.pointSize: 11
                }

                Text {
                    Layout.alignment: Qt.AlignRight

                    text: model.Location
                    color: "#383737"
                    font.pointSize: 9
                }
            }
        }
    }
}
