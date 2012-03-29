// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import ".//"

Rectangle {
    id: mainPage;
    width: 480
    height: 860


    PodcastsTag
    {
        id: allPodcasts
        anchors.fill: parent
    }
}
