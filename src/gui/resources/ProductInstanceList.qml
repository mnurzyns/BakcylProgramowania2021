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


    }
}
