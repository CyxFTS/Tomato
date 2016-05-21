#include "menu.h"
#include "ui_menu.h"
#include <QLabel>

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    setMouseTracking(true);

    main = new UWPButton(this);
    main->setIconSize(QSize(50, 50));
    main->SetButtonIcons(QIcon(":/main_r"), QIcon(":/main_h"), QIcon(":/main_p"));
    main->setStyleSheet("background-color:transparent;");
    main->setGeometry(0,48-48*3,48,48);
    main->res = 1;
    main->setCheckable(true);
    main->name = "main";
    connect(main,&UWPButton::mName,this,&Menu::checkChecked);
    connect(main,&UWPButton::mName,this,&Menu::OOO);

    list = new UWPButton(this);
    list->setIconSize(QSize(48, 48));
    list->SetButtonIcons(QIcon(":/list_r"), QIcon(":/list_h"), QIcon(":/list_p"));
    list->setStyleSheet("background-color:transparent;");
    list->setGeometry(0,96-48*3,48,48);
    list->res = 1;
    list->setCheckable(true);
    list->name = "list";
    connect(list,&UWPButton::mName,this,&Menu::checkChecked);
    connect(list,&UWPButton::mName,this,&Menu::OOO);

    graph = new UWPButton(this);
    graph->setIconSize(QSize(48, 48));
    graph->SetButtonIcons(QIcon(":/graph_r"), QIcon(":/graph_h"), QIcon(":/graph_p"));
    graph->setStyleSheet("background-color:transparent;");
    graph->setGeometry(0,48*3-48*3,48,48);
    graph->res = 1;
    graph->setCheckable(true);
    graph->name = "graph";
    connect(graph,&UWPButton::mName,this,&Menu::checkChecked);
    connect(graph,&UWPButton::mName,this,&Menu::OOO);

    menu = new UWPButton(this);
    menu->setIconSize(QSize(48, 48));
    menu->SetButtonIcons(QIcon(":/menu_r"), QIcon(":/menu_h"), QIcon(":/menu_p"));
    menu->setStyleSheet("background-color:transparent;");
    menu->setGeometry(0,0,48,48);
    menu->res = 1;
    menu->setCheckable(true);
    menu->name = "menu";
    connect(menu, SIGNAL(clicked()), this, SLOT(rxClicked()));

}

Menu::~Menu()
{
    delete ui;
}

void Menu::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timerId)
    {
        int x = main->geometry().x();
        int y = main->geometry().y();
        int w = main->geometry().width();
        int h = main->geometry().height();
        main->setGeometry(x, y + increment, w, h);
        list->setGeometry(x, y + 48 + increment, w, h);
        graph->setGeometry(x, y + 48 * 2 + increment, w, h);
        if (bExpand)
        {
            if (y > 40*0.7)
                increment = 5;
            if (y > 40*0.9)
                increment = 1;
            if (y > 40)
            {
                killTimer(timerId);
                timerId = 0;
                main->setGeometry(x, 48, w, h);
                list->setGeometry(x, 48 + 48, w, h);
                graph->setGeometry(x, 48 + 48 * 2, w, h);
            }
        }
        else
        {
            if (y < -80)
            {
                killTimer(timerId);
                timerId = 0;

            }
        }
    }
    //qDebug()<<"changing";
}

void Menu::checkChecked(const QString &name)
{
    if(name == "main")
    {
        list->setChecked(false);
        list->SetButtonIcons(QIcon(":/list_r"), QIcon(":/list_h"), QIcon(":/list_p"));
        graph->setChecked(false);
        graph->SetButtonIcons(QIcon(":/graph_r"), QIcon(":/graph_h"), QIcon(":/graph_p"));
        main->setChecked(true);
        main->SetButtonIcons(QIcon(":/main_r2"), QIcon(":/main_h2"), QIcon(":/main_p2"));
    }
    if(name == "list")
    {
        main->setChecked(false);
        main->SetButtonIcons(QIcon(":/main_r"), QIcon(":/main_h"), QIcon(":/main_p"));

        graph->setChecked(false);
        graph->SetButtonIcons(QIcon(":/graph_r"), QIcon(":/graph_h"), QIcon(":/graph_p"));
        list->setChecked(true);
        list->SetButtonIcons(QIcon(":/list_r2"), QIcon(":/list_h2"), QIcon(":/list_p2"));
    }
    if(name == "graph")
    {
        main->setChecked(false);
        main->SetButtonIcons(QIcon(":/main_r"), QIcon(":/main_h"), QIcon(":/main_p"));
        list->setChecked(false);
        list->SetButtonIcons(QIcon(":/list_r"), QIcon(":/list_h"), QIcon(":/list_p"));
        graph->setChecked(true);
        graph->SetButtonIcons(QIcon(":/graph_r2"), QIcon(":/graph_h2"), QIcon(":/graph_p2"));
    }
}
