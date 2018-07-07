#include "widget.h"
#include "const.h"

#include <QClipboard>
#include <QDebug>
#include <QPalette>

Widget::Widget(QDialog *parent) : QDialog(parent) {
    /* create the first clip */
    layoutClip = new QVBoxLayout(this);
    createLabel(0, QApplication::clipboard()->text());

    /* setting the geometry for the main window */
//    QRect screen = QApplication::desktop()->screenGeometry();
//    uint16_t heightTaskbar = screen.height() - QApplication::desktop()->availableGeometry().height();
//    uint16_t heightWindow = (labelClip[0]->sizeHint().height() + line->sizeHint().height()) * NUM_CLIPS;
//    this->setGeometry(screen.width() - WIDTH_WINDOW,
//                      screen.height() - heightWindow - heightTaskbar,
//                      WIDTH_WINDOW,
//                      heightWindow);
//    this->setFixedSize(WIDTH_WINDOW, heightWindow);

//    /* creating placeholders for clips */
//    layoutClip = new QVBoxLayout(this);
//    for( uint8_t i=0; i<NUM_CLIPS; i++) {
//        labelClip[i] = new QLabel("label0");
//        layoutClip->addWidget(labelClip[i]);

//        line = new QFrame;
//        line->setFrameStyle(QFrame::HLine | QFrame::Sunken);
//        layoutClip->addWidget(line);
//    }

    /* Listen to any clipboard event */
//    QObject::connect( QApplication::clipboard(), SIGNAL(dataChanged()), this, SLOT(slotNewClip()) );
}

Widget::~Widget() {
}

void Widget::slotNewClip() {
//    /* push down each label */
//    for( uint8_t i=NUM_CLIPS-1; i!=0; i--) {
//        labelClip[i]->setText(labelClip[i-1]->text());
//    }

//    /* set the topmost label with clipboard content */
//    labelClip[0]->setText(QApplication::clipboard()->text());
}

void Widget::createLabel(uint8_t idx, QString str) {
    /* set the clip as string */
    strClip[idx] = str;

    /* trim the string to fit display */
    if(str.length() > LENGTH_CLIP)
        str.resize(LENGTH_CLIP);
    if( str.indexOf('\n') != -1 )
        str.resize(str.indexOf('\n'));

    /* display the string */
    labelClip[idx] = new QLabel(str);
    layoutClip->addWidget(labelClip[idx]);
    line = new QFrame;
    line->setFrameStyle(QFrame::HLine | QFrame::Sunken);
    layoutClip->addWidget(line);
}
