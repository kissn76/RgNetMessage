import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: mainpane.width
    minimumWidth: mainpane.width
    maximumWidth: mainpane.width
    height: mainpane.height
    maximumHeight: mainpane.height
    minimumHeight: mainpane.height
    x: 0
    y: 0
    title: qsTr("RgNetMessage")

    property string username: "talker01"

    signal qmlSignalSubmitMessage(string username, string message)

    Pane {
        id: mainpane
        padding: 5

        ColumnLayout {
            RowLayout {
                Label {
                    text: qsTr("Username:")
                }

                TextField {
                    id: username
                    Layout.fillWidth: true
                    text: "username"
                }
            }

            ColumnLayout {
                TextField {
                    id: messageText
                    Layout.fillWidth: true
                    horizontalAlignment: TextInput.AlignRight
                    readOnly: true
                }

                Numpad {
                    onClicked: messageText.text += text
                    onDeleted: messageText.text = messageText.text.substring(0, messageText.text.length - 1)
                    onSubmitted: {
                        qmlSignalSubmitMessage(username.text, messageText.text);
                        messageText.clear();
                    }
                }
            }
        }
    }
}
