import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

Window {
    property alias text: input.text
    width: 640
    height: 480
    visible: true
    title: qsTr("Product view")

    Text {
        id: input
        text: productId
    }
}
