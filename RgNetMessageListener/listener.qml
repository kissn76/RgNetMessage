import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 300
    height: 300
    title: qsTr("RgNetMessage")

    // Slots
    function qmlSlotSetMessage(sender, message) {
        senderFieldIn.text = sender;
        messageFieldIn.text = message;
    }

    Pane {
        id: mainpane
        width: parent.width
        padding: 5

        ColumnLayout {
            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true
            width: parent.width

            Label {
                text: qsTr("Messages")
            }

            ToolSeparator {
                orientation: Qt.Horizontal
                Layout.fillWidth: true
            }

            RowLayout {
                Label {
                    id: senderFieldIn
                }

                Label {
                    id: messageFieldIn
                }
            }
        }
    }
}
