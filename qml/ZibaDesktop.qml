// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 480
    height: 480
    ListView {
        cacheBuffer: 32
        anchors.fill: parent
        model: feedsModel
        delegate: RssItem {
            newEpisodes: mdl_newEpisodes
            downloaded: mdl_downloaded
            description: mdl_description
            url: mdl_url
        }
    }
}
