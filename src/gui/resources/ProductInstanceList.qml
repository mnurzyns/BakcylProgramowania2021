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
                    font.bold: true
                    font.pointSize: 12
                }

                background: Rectangle {
                    color: "#dddddd"
                }
            }

            GroupBox {
                Layout.fillWidth: true

                Text {
                    text: "Location"
                    font.bold: true
                    font.pointSize: 12
                }

                background: Rectangle {
                    color: "#dddddd"
                }
            }
        }

        ListView {
            id: listOfProductInstances
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            spacing: 3

            model: ProductInstanceModel { }

            delegate: RowLayout {
                width: parent.width
                spacing: 5

                GroupBox {
                    id: idGroupBox
                    Layout.preferredWidth: parent.width / 10
                    clip: true

                    Text {
                        width: parent.width

                        text: "ID: " + model.ID
                        font.bold: true
                        font.pointSize: 12
                    }

                    background: Rectangle {
                        color: "#efefef"
                    }
                }

                GroupBox {
                    id: locationGroupBox
                    Layout.fillWidth: true
                    clip: true

                    Text {
                        width: parent.width
                        text: model.Location
                        horizontalAlignment: Text.AlignRight
                        color: "#383737"
                        font.pointSize: 11
                    }

                    background: Rectangle {
                        color: "#fafafa"
                    }
                }
            }
        }
    }
}
