import QtQuick
import QtQuick.Controls 2.15

Item {
    id: root
    signal changeView()

    ListView {
        anchors.fill: parent
        model: StudentsModel
        delegate: studentDelegate
    }

    Component {
        id: studentDelegate
        Rectangle {
            width: parent.width
            height: 100
            color: "lightblue"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                   console.log("Clicked on:", model)
                }
            }

            Text {
               id: nameLabel
               anchors.top: parent.top
               anchors.left: parent.left
               text: model.firstName + " " + model.lastName
               font.pixelSize: 24
            }

            Text {
               id: groupLabel
               anchors.top: nameLabel.bottom
               anchors.left: parent.left
               text: "Група: " + model.groupName
               font.pixelSize: 16
            }

            Text {
               anchors.top: groupLabel.bottom
               anchors.left: parent.left
               text: "Email: " + model.email
               font.pixelSize: 16
            }
        }
    }
}
