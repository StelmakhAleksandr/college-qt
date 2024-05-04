import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.15

Item {
    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        Label {
            text: "College App"
            font.pixelSize: 24
            horizontalAlignment: Qt.AlignHCenter
        }

        Button {
            text: "Студенти"
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                console.log("Navigating to Students view")
            }
        }

        Button {
            text: "Вчителі"
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                console.log("Navigating to Teachers view")
            }
        }

        Button {
            text: "Співробітники"
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                console.log("Navigating to Staff view")
            }
        }
    }
}
