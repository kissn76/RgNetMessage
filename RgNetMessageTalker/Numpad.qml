import QtQuick 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Rectangle {
    id: root
    width: nplayout.width
    height: nplayout.height

    property string text;

    signal clicked();
    signal deleted();
    signal submitted();

    GridLayout {
        id: nplayout
        columns: 3

        Repeater {
            model: 10

            Button {
                text: model.index

                onClicked: {
                    root.text = text;
                    root.clicked();
                }
            }
        }

        Button {
            text: qsTr("Del")

            onClicked: root.deleted()
        }

        Button {
            text: qsTr("Ok")

            onClicked: root.submitted()
        }
    }
}
