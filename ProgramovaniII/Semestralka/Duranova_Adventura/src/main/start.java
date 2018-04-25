package main;

import javafx.application.Application;
import static javafx.application.Application.launch;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;
import logika.Hra;
import logika.IHra;
import uiText.TextoveRozhrani;

/**
 *
 * @author Michaela Duranova
 */
public class start extends Application {

    private IHra hra;

    @Override
    public void start(Stage primaryStage) {
        hra = new Hra();// vytvoření objektu hry, smayali jsme IHra 

        //StackPane root = new StackPane();
        BorderPane border = new BorderPane();
        TextArea centerTextArea = new TextArea();// new TextArea = volani konstruktoru TextAreaa nechali jsme ji prazdnou
        centerTextArea.setText(hra.vratUvitani());
        border.setCenter(centerTextArea);

        Label zadejPrikazLabel = new Label("Zadej prikaz: ");// vytvoreni textu v Okne, Label = nemenitelny text
        zadejPrikazLabel.setFont(Font.font("Arial", FontWeight.BOLD, 16));

        FlowPane dolniFlowPane = new FlowPane();
        dolniFlowPane.setAlignment(Pos.CENTER);
        TextField prikazTextField = new TextField(); // prazdne textove pole pro psani
        //dolniFlowPane.getChildren().add(zadejPrikazLabel);// do kolekce getChildren metodou add pridame 
        //dolniFlowPane.getChildren().add(prikazTextField);TextField prikazTextField = new TextField(); // prazdne textove pole pro psani
        // vlozeno se slidu 14
        prikazTextField.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent event) {// handle je metoda prvniho radku
                String radek = prikazTextField.getText(); // vezme si napsany text
                String text = hra.zpracujPrikaz(radek);
                centerTextArea.appendText("\n\n" + radek + "\n"); //
                centerTextArea.appendText("\n" + text + "\n");
                
                // aktualizuj vychody
                border.setRight(nastavVychody());// dame do metody start
                
                prikazTextField.setText(""); // vyprazneni radku
                if (hra.konecHry()) {
                    prikazTextField.setEditable(false); // po konci hry udela radek needitovatelny
                   
                }
            }

        });

        dolniFlowPane.getChildren().addAll(zadejPrikazLabel, prikazTextField);

        border.setBottom(dolniFlowPane);

        FlowPane obrazekPane = new FlowPane();// vložení obráyku

        ImageView obrazek = new ImageView(new Image(start.class.getResourceAsStream("/zdroje/Amy.png"), 400, 300, false, false));// obrazek je nazev noveho obrazky,´= new … je konstruktor, pak je adresa
        obrazekPane.setAlignment(Pos.CENTER);// centruje panel

        obrazekPane.getChildren().add(obrazek);

        border.setTop(obrazekPane);
        
         // aktualizuj vychody
        border.setRight(nastavVychody());

        Scene scene = new Scene(border, 600, 450);// panel scény

        primaryStage.setTitle("Hra Vyvenci Pejska");
        primaryStage.setScene(scene);// 
        prikazTextField.requestFocus();
        primaryStage.show();
    }

 private ListView nastavVychody() {
        ListView<String> list = new ListView<>();
        ObservableList<String> data = FXCollections.observableArrayList();
        list.setItems(data);
        list.setPrefWidth(100);

        String vychody = hra.getHerniPlan().getAktualniProstor().seznamVychodu();

        String[] oddeleneVychody = vychody.split(" ");
        for (int i = 1; i < oddeleneVychody.length; i++) {
            data.add(oddeleneVychody[i]);
        }
        return list ;
}

    

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        if (args.length == 0) {
            launch(args);
        } else {
            if (args[0].equals("-text")) {
                IHra hra = new Hra();
                TextoveRozhrani ui = new TextoveRozhrani(hra);
                ui.hraj();
            } else {
                System.out.println("Neplatny parametr");
            }
        }
    }

}
