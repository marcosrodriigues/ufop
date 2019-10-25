import { Component, OnInit } from '@angular/core';
import { InventarioService } from 'src/app/service/inventario.service';
import { QuestionarioService } from 'src/app/service/questionario.service';
import  * as $ from 'jquery';

@Component({
  selector: 'app-inventory',
  templateUrl: './inventory.component.html',
  styleUrls: ['./inventory.component.css']
})
export class InventoryComponent implements OnInit {

  constructor(private _inventory : InventarioService,
              private _questionario: QuestionarioService) { }

  questions : any = [];
  answers: any = [];

  ngAfterContentInit() {
    
  }

  ngOnInit() {
    this._questionario.getAll().subscribe(data => {
      this.questions = data;
    });

    this._inventory.getInventario().subscribe(data => {
      this.answers = data;
      this.initAnswer();      
    });
  }

  initAnswer() {
    for (let ans of this.answers) {
      for (let q of this.questions) {
        if (q.id == ans.pergunta.id) {
          $("#Q" + q.id + "_" + ans.resposta).attr("checked", true);
        }
      }
    }
  }

  select(answer, question){
    let inventory = {
      resposta: answer,
      pergunta: {
        id: question        
      }
    }

    let changed = false;
    for (let ans of this.answers) {
      if (ans.pergunta.id == question) {
        ans.resposta = answer;
        changed = true;
        break;
      }
    }

    if (!changed) {
      this.answers.push(inventory);
    }
  }

  send() {
    this._inventory.save(this.answers).subscribe(data => {
      alert('Inventário atualizado!');
    })
  }

}
