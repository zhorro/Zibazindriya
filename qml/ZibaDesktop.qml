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
            newEpisodes:  mdl_newEpisodes // Количество новых эпизодов
            downloaded:   mdl_downloaded // Скачаных (готовых к прослушиванию)
            url:          mdl_url // Ссылка на ленту

            title:        mdl_title // Заголовок
            icon:         mdl_icon // Иконка
            tag:          mdl_tag // Тэги
            deleteInDays: mdl_deleteInDays // Время жизни

        }
    }
}
