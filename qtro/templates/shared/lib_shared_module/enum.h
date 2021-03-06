{% set class = '{0}'.format(enum) %}
/****************************************************************************
** This is an auto-generated file.
** Do not edit! All changes made to it will be lost.
****************************************************************************/

#ifndef {{class|upper}}_H
#define {{class|upper}}_H

#include <QtCore>
#include <QtQml>

{{module|open_ns}}

class {{enum}}Enum {
    Q_GADGET
public:
    enum {{enum}} {
{% for member in enum.members %}
        {{member.name}} = {{member.value}}{% if not loop.last %},
        {%endif%}
{% endfor %}

    };
    {%if enum.is_flag%}
    Q_DECLARE_FLAGS({{enum}}Flags, {{enum}})
    Q_FLAG({{enum}})
    {% else %}
    Q_ENUM({{enum}})
    {%endif%}

    static {{enum}} toEnum(quint8 v, bool *ok) {
        if (ok) {
            *ok = true;
        }
        switch (v) {
{% for member in enum.members %}
        case {{member.value}}: return {{member.name}};
{% endfor %}
        default:
            if (ok) {
                *ok = false;
            }
            return {{enum|defaultValue}};
        }
    }

    static void registerTypes(const char* uri="{{module}}") {
        qRegisterMetaType<{{enum|ns}}{{enum|returnType}}>();
        qRegisterMetaTypeStreamOperators<{{enum|ns}}{{enum|returnType}}>();
        qmlRegisterUncreatableType<{{enum|ns}}{{enum}}Enum>(uri, 1, 0, "{{enum}}", "Enumeration type can not be created");
    }
};

{% if enum.is_flag %}
Q_DECLARE_OPERATORS_FOR_FLAGS({{enum}}Enum::{{enum}}Flags)
{% endif %}


{{module|close_ns}}

inline QDataStream &operator<<(QDataStream &ds, const {{module|ns}}{{enum}}Enum::{{enum}} &obj)
{
    quint8 val = obj;
    ds << val;
    return ds;
}

inline QDataStream &operator>>(QDataStream &ds, {{module|ns}}{{enum}}Enum::{{enum}} &obj) {
    bool ok;
    quint8 val;
    ds >> val;
    obj = {{module|ns}}{{enum}}Enum::toEnum(val, &ok);
    if (!ok) {
        qWarning() << "received an invalid enum value for typeState, value =" << val;
    }
    return ds;
}

#endif // {{class|upper}}_H
