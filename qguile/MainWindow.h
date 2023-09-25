#ifndef GUILE_INTERPRETER_MAIN_WINDOW
#define GUILE_INTERPRETER_MAIN_WINDOW

#include <QMainWindow>
#include <QTextEdit>
#include <QTextBrowser>
#include <QPushButton>
#include <QGridLayout>
#include <exception>

#include <libguile.h>


// Header only Scheme Console widget
class SchemeConsole : public QWidget {

    Q_OBJECT

public:
    SchemeConsole() {
        // Add the widgets to the layout
        mLayout.addWidget(&mTextEdit, 0, 0);
        mLayout.addWidget(&mTextBrowser, 1, 0);
        mLayout.addWidget(&mButton, 2, 0);
        mButton.setText("Evaluate");
        setLayout(&mLayout);

        // Connect the button to the evaluate function
        // I prefer to use a lambda function to make the evaluate slots take a QString as argument
        connect(&mButton, &QPushButton::clicked, this, [this]() {
            evaluate(mTextEdit.toPlainText());
        });
    }

    static void* c_guile_run_function(void *qstring) {
        // This function is called by the evaluate slot with a pointer to a QString representing the scheme code to evaluate
        // It need to be static, because it is called by scm_with_guile, which is a C function

        // Convert the void pointer to a QString pointer
        QString *code = (QString *) qstring;

        // Evaluate the code
        SCM val = scm_eval_string(scm_from_locale_string(code->toStdString().c_str()));
        SCM str = scm_c_make_string(0, SCM_UNDEFINED);
        SCM port = scm_mkstrport(SCM_INUM0, str, SCM_OPN | SCM_WRTNG, "aux");
        scm_write(val, port);
        SCM s = scm_strport_to_string(port);
        if (!scm_is_string(s)) {
            return (void *) (char *) "Not a string";
        }
        return scm_to_locale_string(s);
    }

public slots:
    void evaluate(QString code) {
        QString result;
        try {
            // Call the c_guile_run_function with a pointer to the code
            char *txt = (char *) scm_with_guile(c_guile_run_function, &code);

            // Convert the c string to a QString
            result = QString::fromLocal8Bit(txt);
        } catch (std::exception &e) {
            // The guile_error throw an exception, which is catched here
            result = QString::fromStdString(e.what());
        }

        // Append the result in green color using html
        mTextBrowser.append(QString("<font color=\"green\">%1</font>").arg(result));
    }

public:
    QGridLayout mLayout;
    QTextEdit mTextEdit;
    QTextBrowser mTextBrowser;
    QPushButton mButton;

};


#endif
