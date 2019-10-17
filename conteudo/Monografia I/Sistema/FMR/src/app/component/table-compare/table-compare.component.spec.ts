import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { TableCompareComponent } from './table-compare.component';

describe('TableCompareComponent', () => {
  let component: TableCompareComponent;
  let fixture: ComponentFixture<TableCompareComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ TableCompareComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(TableCompareComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
