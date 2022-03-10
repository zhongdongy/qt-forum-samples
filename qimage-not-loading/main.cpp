#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <QFile>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  auto window = QMainWindow();
  window.setGeometry(200, 200, 480, 320);

  QFile f(":/resources/images/default-background.png");
  f.open(QIODevice::OpenModeFlag::ReadOnly);
  QByteArray byte_array = f.readAll();
  qDebug() << "Bytes length: " << byte_array.length();
  QImage img = QImage::fromData(byte_array);
  qDebug() << "Is QImage instance null: " << img.isNull();

  window.show();
  return QApplication::exec();
}
