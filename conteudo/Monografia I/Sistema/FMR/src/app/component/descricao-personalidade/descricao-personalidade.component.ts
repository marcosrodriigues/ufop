import { Component, OnInit, Input } from '@angular/core';
import { PercentPipe } from '@angular/common';
import { PersonalidadeService } from 'src/app/service/personalidade.service';

@Component({
  selector: 'app-descricao-personalidade',
  templateUrl: './descricao-personalidade.component.html',
  styleUrls: ['./descricao-personalidade.component.css']
})
export class DescricaoPersonalidadeComponent implements OnInit {

  @Input("personality") personalidade: any = {};
  @Input("short") short : boolean = false;

  percent : any = {};

  constructor(private _personalidade : PersonalidadeService) { }

  ngOnChanges() {
    this.setPercentage();
  }

  ngOnInit() {
    this.setPercentage();
  }

  setPercentage() {
    this.percent = this._personalidade.setPercentage(this.personalidade);
  }
}
