#include "jaudio.h"
#include "ui_jaudio.h"

#include <QAudioRecorder>
#include <QAudioDeviceInfo>

jAudio::jAudio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jAudio)
{
    ui->setupUi(this);
    this->jSetup();
}

jAudio::~jAudio()
{
    delete ui;
}

void jAudio::jSetup(void){

    ui->bActionGroup->setDisabled(true);
    QAudioDeviceInfo device = QAudioDeviceInfo::defaultInputDevice();
    QStringList codecs = device.supportedCodecs();
    QList<int> sampleRates = device.supportedSampleRates();

    this->jFillComboBox(ui->cCodecs, codecs);

    int nCodecs = codecs.count();
    ui->lCodecsNumber->setText(QString::number(nCodecs) + " available");
    for (int i = 0; i< codecs.count(); i++){
        ui->cCodecs->addItem(codecs[i], i);
    }
    ui->cCodecs->setCurrentIndex(0);

    int nSample = sampleRates.count();
    ui->lSampleNumber->setText(QString::number(nSample) + " available");
    for (int i = 0; i< sampleRates.count(); i++){
        ui->cSample->addItem(QString::number(sampleRates[i]) + " Hz", i);
    }
    ui->cSample->setCurrentIndex(0);



    ui->lDeviceName->setText( device.deviceName() );



    this->jInfo("Ready!     =)");
    //this->jInfo(QAudioDeviceInfo::availableDevices(QAudio::AudioInput));
}

/*-------------------------------------------------------------------
 * Javi tools
 *-------------------------------------------------------------------*/
void jAudio::jFillComboBox(QComboBox *combo, QStringList data){
    for (int i = 0;  i< options.count(); i++){
        comboBox->addItem(data[i],i);
    }
}

void jAudio::jInfo(QString msg){

    ui->jInfo->append(msg);
    ui->jInfo->show();
}

/*-------------------------------------------------------------------
 * Signals
 *-------------------------------------------------------------------*/
void jAudio::on_bRecord_clicked()
{
    ui->bActionGroup->setEnabled(true);

    /*
    QAudioRecorder audioRecorder;
    QAudioEncoderSettings audioSetings;
    audioSetings.setCodec("audio/amr");
*/

    this->jInfo("Recording...");

}
