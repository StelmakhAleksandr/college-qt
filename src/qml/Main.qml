import QtQuick
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("College App")

    Loader {
        id: loader
        anchors.fill: parent
        source: "TeachersView.qml"

        onLoaded: {
            loader.item.changeView.connect(changeView)
        }
    }


    function changeView(src) {
        loader.source = src
    }



}
