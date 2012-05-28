// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import com.nokia.meego 1.1      // MeeGo components
import QtQuick 1.1

PageStackWindow {
    id: appWindow
    showToolBar: true
    showStatusBar: true
    anchors.margins: 0
    initialPage: testPageWithLists

    TestPageWithLists {
        id: testPageWithLists
    }

    ToolBarLayout {
        id: commonTools
        visible: true
        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked: (myMenu.status === DialogStatus.Closed) ? myMenu.open() : myMenu.close()
        }
    }

    Menu {
        id: myMenu
        visualParent: pageStack
        MenuLayout {
            MenuItem { text: qsTr("Sample menu item") }
        }
    }
}

