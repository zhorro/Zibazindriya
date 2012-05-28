// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import com.nokia.meego 1.1      // MeeGo components
import QtQuick 1.1

Page {
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
