import QtQuick
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Loader {
        id: loader
        anchors.fill: parent
        source: "StudentsView.qml"

        onLoaded: {
            loader.item.changeView.connect(changeView)
        }
    }


    function changeView() {
        console.log("change view")
        loader.source = "TestView.qml"
    }



}
