bool flag = true;
bool flag_1 = true;
bool flag_2 = true;

float volumen_vacio = 0.0;
float volumen_actual = 0.0;
float capacidad = 0.0;

float volumen_vacio_c = 0.0;
float volumen_actual_c = 0.0;

// Función para administrar los mensajes entre Telegram y el ESP32
void handleNewMessages(int numNewMessages)
{
    Serial.println("---------------------------------------");
    Serial.print("Número nuevo de mensajes: ");
    Serial.println(String(numNewMessages));
    Serial.print("Comando ingresado en telegram: ");
    for (int i = 0; i < numNewMessages; i++)
    {
        // Chat id del solicitante
        String chat_id = String(bot.messages[i].chat_id);
        // Condición para validar que los id sean autorizados
        // Si entra en la condición no se autoriza el id y se da el mensaje correspondiente
        if ((chat_id != CHAT_ID_2) && (chat_id != CHAT_ID))
        {
            // Función para mandar mensajes a un usuario, identificandose mediante su id
            bot.sendMessage(chat_id, "Usuario no autorizado", "");
            // Imprime en el monitor serial el id que
            Serial.println("El id no autorizado es: ");
            Serial.println(chat_id);
            continue;
        }
        // Guarda en text el texto que ingresó el usuario en Telegram
        String text = bot.messages[i].text;
        // Imprime en el monitor Serial el mensaje que se mandó mediante Telegram
        Serial.println(text);
        // Obten el nombre con el que está registrado el usuario en Telegram
        String from_name = bot.messages[i].from_name;
        // Imprime en el monitor Serial los datos del usuario
        Serial.print("Comando ingresado por el usuario: ");
        Serial.println(from_name);
        Serial.print("Con Id: ");
        Serial.println(chat_id);
        // Dependiendo de lo que haya ingresado el usuario, se ejecutan las siguientes opciones
        // Muestra en telegram en menú de opciones que puede seleccionar el usuario
        if (text == "/start")
        {
            String welcome = "Bienvenid@, " + from_name + ".\n\n";
            welcome += "Usa los siguientes comandos para controlar las salidas.\n\n";
            welcome += "/led_on para encender el led \n";
            welcome += "/led_off para apagar el led \n";
            welcome += "/get_distance para obtener la distancia entre el sensor y el objeto \n";
            welcome += "/get_data para obtener los datos del tinaco \n";
            bot.sendMessage(chat_id, welcome, "");
        }
        else if (text == "/led_on")
        {
            bot.sendMessage(chat_id, "El estado del led es encendido", "");
            ledState = HIGH;
            digitalWrite(ledPin, ledState);
        }
        else if (text == "/led_off")
        {
            bot.sendMessage(chat_id, "El estado del led es apagado", "");
            ledState = LOW;
            digitalWrite(ledPin, ledState);
        }
        else if (text == "/pudul")
        {
            bot.sendMessage(chat_id, "Te amooo DanyRex", "");
        }
        else if (text == "/get_distance")
        {
            String distance_message = "La distancia entre el sensor y el objeto es: " + String(DISTANCIA) + " [cm]";
            bot.sendMessage(chat_id, distance_message, "");
            Serial.println(distance_message);
        }
        else if (text == "/get_data")
        {
            if (capacidad > 100 || capacidad < 0)
            {
                String out_of_range_message;
                out_of_range_message = "El sensor se encuentra fuera de rango";
                bot.sendMessage(chat_id, out_of_range_message, "");
            }
            else
            {
                String message_alert_data;
                message_alert_data = "--------------------------------------------\n";
                message_alert_data += "📄 DATOS DEL TANQUE 📄\n";
                message_alert_data += "\nCapacidad al = " + String(capacidad) + "%";
                message_alert_data += "\n\nDistancia del sensor al agua = " + String(DISTANCIA) + " [cm]";
                message_alert_data += "\n\nVolumen total       = " + String(volumen_total_c) + " [cm^3]";
                message_alert_data += "\nVolumen con agua  = " + String(volumen_actual_c) + " [cm^3]";
                message_alert_data += "\nVolumen sin agua = " + String(volumen_vacio_c) + " [cm^3]";
                message_alert_data += "\n --------------------------------------------";
                bot.sendMessage(chat_id, message_alert_data, "");
            }
        }
        else
        {
            Serial.println("Comando inválido");
            bot.sendMessage(chat_id, "Comando inválido", "");
        }
    }
}

void messageAlert()
{
    if (capacidad >= 0 && capacidad < 20 && flag_1 && !flag_2)
    {
        flag_1 = false;
        flag_2 = true;
        String message_alert_low;
        message_alert_low = "--------------------------------------------\n";
        message_alert_low += " ⬇️🔴 ALERTA ⬇️🔴  \n";
        message_alert_low += "\nCapacidad al = " + String(capacidad) + "%";
        message_alert_low += "\n\nNivel por debajo del 20% recargar tanque";
        message_alert_low += "\n\nVolumen total       = " + String(volumen_total_c) + " [cm^3]";
        message_alert_low += "\nVolumen con agua  = " + String(volumen_actual_c) + " [cm^3]";
        message_alert_low += "\nVolumen sin agua = " + String(volumen_vacio_c) + " [cm^3]";
        message_alert_low += "\n --------------------------------------------";
        bot.sendMessage("1289944523", message_alert_low, "");
    }
    else if (capacidad > 90 && capacidad <= 100 && !flag_1 && flag_2)
    {
        flag_1 = true;
        flag_2 = false;
        String message_alert_high;
        message_alert_high = "--------------------------------------------\n";
        message_alert_high += " ⬆️🟢 ALERTA ⬆️🟢 \n";
        message_alert_high += "\nCapacidad al = " + String(capacidad) + "%";
        message_alert_high += "\n\nNivel mayor al 90% desconectar bomba tanque";
        message_alert_high += "\n\nVolumen total       = " + String(volumen_total_c) + " [cm^3]";
        message_alert_high += "\nVolumen con agua  = " + String(volumen_actual_c) + " [cm^3]";
        message_alert_high += "\nVolumen sin agua = " + String(volumen_vacio_c) + "[cm^3]";
        message_alert_high += "\n --------------------------------------------";
        bot.sendMessage("1289944523", message_alert_high, "");
    }
    /*
    if (capacidad >= 0 && capacidad < 20)
    {
        ledState = HIGH;
        digitalWrite(ledPin, ledState);
    }
    else
    {
        ledState = LOW;
        digitalWrite(ledPin, ledState);
    }
    */
}

void flagAlert()
{
    while (flag == true)
    {
        if (capacidad < 20)
        {
            flag_1 = true;
            flag_2 = false;
            flag = false;
        }
        else if (capacidad > 90)
        {
            flag_1 = false;
            flag_2 = true;
            flag = false;
        }
    }
}

void usinghandleNewMessages()
{
    /*
    volumen_vacio = (LARGO) * (ANCHO) * (DISTANCIA);
    volumen_actual = (volumen_total) - (volumen_vacio);
    capacidad = ((100) * volumen_actual) / volumen_total;
    */

    //
    volumen_vacio_c = (Pi) * (radio) * (radio) * (DISTANCIA);
    volumen_actual_c = (volumen_total_c) - (volumen_vacio_c);
    capacidad = ((100) * volumen_actual_c) / volumen_total_c;
    //

    if (millis() > lastTimeBotRan + botRequestDelay)
    {
        int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
        while (numNewMessages)
        {
            handleNewMessages(numNewMessages);
            numNewMessages = bot.getUpdates(bot.last_message_received + 1);
        }
        lastTimeBotRan = millis();
    }
    flagAlert();
    messageAlert();
}
