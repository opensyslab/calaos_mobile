import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

ButtonStyle {
    background: Item {
        property bool down: control.pressed || (control.checkable && control.checked)
        BorderImage {
            source: "qrc:/img/back_items_home.png"
            border.left: 5 * calaosApp.density; border.top: 5 * calaosApp.density
            border.right: 5 * calaosApp.density; border.bottom: 5 * calaosApp.density
            anchors.fill: parent
            opacity: down?0:1
            Behavior on opacity { PropertyAnimation { duration: 50 } }
        }
        BorderImage {
            source: "qrc:/img/back_items_home_glow.png"
            border.left: 5 * calaosApp.density; border.top: 5 * calaosApp.density
            border.right: 5 * calaosApp.density; border.bottom: 5 * calaosApp.density
            anchors.fill: parent
            opacity: down?1:0
            Behavior on opacity { PropertyAnimation { duration: 50 } }
        }
    }
    padding {
            top: 12 * calaosApp.density
            left: 12 * calaosApp.density
            right: 12 * calaosApp.density
            bottom: 12 * calaosApp.density
    }
    label: Text {
        text: control.text
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font { pointSize: 12 * calaosApp.density }
        color: "#e7e7e7"
        anchors.fill: parent
    }
}