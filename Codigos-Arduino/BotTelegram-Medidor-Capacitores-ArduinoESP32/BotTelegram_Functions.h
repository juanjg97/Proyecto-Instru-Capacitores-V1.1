
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
        else if (text=="/get_distance") 
        {
          String distance_message = "La distancia entre el sensor y el objeto es: "+ String(DISTANCIA)+" [cm]";
          bot.sendMessage(chat_id,distance_message,"");
          Serial.println(distance_message);
          unsigned long hour = hour();
          unsigned long minute = minute();
          String time_data=String(hour)+":"+String(minute);
          Serial.println(time_data);
        }
        // Si no coincide ningún comando con lo que ingresó el usuario
        else
        {
            Serial.println("Comando inválido");
            bot.sendMessage(chat_id, "Comando inválido", "");
        }
    }

}

void usinghandleNewMessages()
{
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
        if (DISTANCIA <10)
    {
      bot.sendMessage("1289944523", "Nivel por debajo de 10", "");
    }
}
