/******************************************
  * uWebKit 
  * (c) 2014 THUNDERBEAST GAMES, LLC
  * website: http://www.uwebkit.com email: sales@uwebkit.com
  * Usage of this source code requires a uWebKit Source License
  * Please see UWEBKIT_SOURCE_LICENSE.txt in the root folder 
  * for details
*******************************************/

#pragma once

#include <QtWebKitWidgets>

namespace UWK
{

class WebView;

class WebPage : public QWebPage
{
    Q_OBJECT

    QString userAgentOverride_;

protected:

    WebView* view_;
    void javaScriptConsoleMessage ( const QString& message, int lineNumber, const QString& sourceID );
    QString userAgentForUrl(const QUrl & url) const;

    void javaScriptAlert (QWebFrame* frame, const QString& message );
    bool javaScriptConfirm ( QWebFrame* frame, const QString& message );

public:

    explicit WebPage(WebView* view);

    bool acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request, NavigationType type);

    void setUserAgentOverride(const QString& agent) { userAgentOverride_ = agent; }


public slots:

    void repaintRequested(const QRect & dirtyRect);

};

}
