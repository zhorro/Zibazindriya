// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 360
    height: 360

    ListView {
        anchors.fill: parent
        model: feedsModel
        delegate: RssItem {
            width: parent.width;
            newEpisodes: mdl_newEpisodes;
            downloaded: mdl_downloaded;
            description: mdl_description;
            url: mdl_url;
        }
    }
}
