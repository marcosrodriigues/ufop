import { Component, OnInit } from '@angular/core';
import { InventarioService } from 'src/app/service/inventario.service';
import { QuestionarioService } from 'src/app/service/questionario.service';

@Component({
  selector: 'app-inventory',
  templateUrl: './inventory.component.html',
  styleUrls: ['./inventory.component.css']
})
export class InventoryComponent implements OnInit {

  constructor(private _inventory : InventarioService,
              private _questionario: QuestionarioService) { }

  questions : any = [];

  ngOnInit() {
    this._questionario.getAll().subscribe(data => {
      this.questions = data;
    })
  }

}
