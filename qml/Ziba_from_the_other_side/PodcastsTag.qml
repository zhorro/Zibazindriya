// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import ".//"

Rectangle {
    id: podcastsTag
    property alias source: tagRepeater.model
    width: 640
    height: 200

    Column {
        anchors.fill: parent
        Repeater {
            id: tagRepeater
            PodcastFolder {
                newCasts: newCasts
                downCasts: downCasts
                icon: icon
                description: description
            }
        }
    }
}
