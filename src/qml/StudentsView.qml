import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

Item {
    id: root
    signal changeView()

    anchors.fill: parent
    anchors.margins: 5


    Text {
        id: studentsLabel
        text: "Список студентів"
        font.pixelSize: 24
        color: Material.accent
        horizontalAlignment: Text.AlignHCenter
        anchors.horizontalCenter: parent.horizontalCenter // Анкор для горизонтального центрування
    }

    ListView {
        width: parent.width
        anchors.top: studentsLabel.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 5
        model: StudentsModel
        spacing: 5
        delegate: studentDelegate
    }

    Component {
        id: studentDelegate
        Rectangle {
            width: parent.width
            height: 150
            color: Material.background
            border.color: Material.accent
            border.width: 2
            radius: 10
            smooth: true

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Clicked on:", model)
                }
            }

            Row {
                spacing: 10
                anchors.centerIn: parent

                Column {
                    spacing: 10

                    Text {
                        text: model.firstName + " " + model.lastName
                        font.pixelSize: 16
                        color: Material.accent
                    }

                    Text {
                        text: "Група: " + model.groupName
                        font.pixelSize: 16
                        color: Material.accent
                    }
                }

                Column {
                    spacing: 10

                    Text {
                        text: "Email: " + model.email
                        font.pixelSize: 16
                        color: Material.accent
                    }

                    Text {
                        text: "Телефон: " + model.phoneNumber
                        font.pixelSize: 16
                        color: Material.accent
                    }
                }
            }
        }
    }
}
